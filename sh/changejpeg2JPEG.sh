ds=$(find . -maxdepth 1 -mindepth 1 -type d)
for d in $ds; do
    case $1 in
        1 ) 
              as=$(find $d -maxdepth 1 -mindepth 1 -name "*.jpeg")
              for a in $as; do
                  newname=${a%.*}.JPEG
                  echo $a"-->"$newname
                  mv $a $newname
              done
              ;;
        2 )
              as=$(find $d -maxdepth 1 -mindepth 1 -name "*.JPEG")
              for a in $as; do
                  newname=${a%.*}.jpeg
                  echo $a"-->"$newname
                  mv $a $newname
              done
              ;;
        * )   echo "please enter argument 1 or 2"; exit
     esac   
done
