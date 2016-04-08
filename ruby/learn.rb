#!/usr/bin/env ruby

# END在整个脚本结束执行后执行
END {
  puts "Ruby结束了"
}

# puts用于输出
puts "Hello World!";

# <<用于定义多行的字符
print <<EOF
哈哈哈
嘿嘿嘿
EOF

# BEGIN在整个脚本开始执行前执行
BEGIN {
  puts "初始化Ruby"
}

# 格式化输出
puts "计算结果为#{16 ** (1 / 4.0)}"
name = "Ruby"
puts "#{name}是一门很棒的语言"

# 数组
nums = Array.new(4) { |e| e = e }
puts "#{nums}"
nums2 = Array.[](1, 2, 3, 4, 5)
puts "#{nums2}"
nums3 = Array(0..9)
puts "#{nums3}"
array = ["fred", 10, 3.14, "This is a string"]  # Array各个元素可以是不同类型
array.each do |i|
  puts i
end

# 字典类型
dict = {"red" => 1, "blue" => 2, "green" => 3}
dict.each do |key, value|
  puts "#{key} is #{value}"
end
