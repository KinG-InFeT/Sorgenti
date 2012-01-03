#!/usr/bin/env ruby

array1=[1,5,3,2,7,4,9,6,8]

#oppure inserendoli con una "serie"
#array1 = (1..10).to_a

puts "#{array1}"

#aggiungo un valore
array1 << 10

#ora ordino l'array
array1.sort!

puts "#{array1}"
