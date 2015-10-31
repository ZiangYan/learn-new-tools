#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include "learnproto/proto/addressbook.pb.h"
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

using namespace std;
using google::protobuf::io::FileInputStream;
using google::protobuf::io::FileOutputStream;
using google::protobuf::io::ZeroCopyInputStream;
using google::protobuf::io::ZeroCopyOutputStream;

bool ReadProtoFromTextFile(const char* filename, google::protobuf::Message* proto) {
   int fd = open(filename, O_RDONLY);
   FileInputStream* input = new FileInputStream(fd);
   bool success = google::protobuf::TextFormat::Parse(input, proto);
   delete input;
   close(fd);
   return success;
}

bool WriteProtoToTextFile(const google::protobuf::Message& proto, const char* filename){
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  FileOutputStream* output = new FileOutputStream(fd);
  bool success = google::protobuf::TextFormat::Print(proto, output);
  delete output;
  close(fd);
  return success;
}
// This function fills in a Person message based on user input.
void PromptForAddress(tutorial::Person* person) {
  cout << "Enter person ID number: ";
  int id;
  cin >> id;
  person->set_id(id);
  cin.ignore(256, '\n');

  cout << "Enter name: ";
  getline(cin, *person->mutable_name());

  cout << "Enter email address (blank for none): ";
  string email;
  getline(cin, email);
  if (!email.empty()) {
    person->set_email(email);
  }

  while (true) {
    cout << "Enter a phone number (or leave blank to finish): ";
    string number;
    getline(cin, number);
    if (number.empty()) {
      break;
    }

    tutorial::Person::PhoneNumber* phone_number = person->add_phone();
    phone_number->set_number(number);

    cout << "Is this a mobile, home, or work phone? ";
    string type;
    getline(cin, type);
    if (type == "mobile") {
      phone_number->set_type(tutorial::Person::MOBILE);
    } else if (type == "home") {
      phone_number->set_type(tutorial::Person::HOME);
    } else if (type == "work") {
      phone_number->set_type(tutorial::Person::WORK);
    } else {
      cout << "Unknown phone type.  Using default." << endl;
    }
  }
}

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
    return -1;
  }

  tutorial::AddressBook address_book;

  // {
  //   // Read the existing address book.
  //   fstream input(argv[1], ios::in | ios::binary);
  //   if (!input) {
  //     cout << argv[1] << ": File not found.  Creating a new file." << endl;
  //   } else if (!address_book.ParseFromIstream(&input)) {
  //     cerr << "Failed to parse address book." << endl;
  //     return -1;
  //   }
  // }
  {
      bool success = ReadProtoFromTextFile(argv[1], address_book.add_person());
      if (!success) {
          std::cout << "Parse from " << argv[1] << " error" << std::endl;
          return -1;
      }
  }

  // Add an address.
  PromptForAddress(address_book.add_person());

  // {
  //   // Write the new address book back to disk.
  //   fstream output(argv[1], ios::out | ios::trunc | ios::binary);
  //   if (!address_book.SerializeToOstream(&output)) {
  //     cerr << "Failed to write address book." << endl;
  //     return -1;
  //   }
  // }
  {
      bool success = WriteProtoToTextFile(address_book, argv[1]);
      if (!success) {
          cout << argv[1] << " write failed." << std::endl;
      }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
