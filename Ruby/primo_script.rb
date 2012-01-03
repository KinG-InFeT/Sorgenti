#!/usr/bin/env ruby

puts "Come ti chiami?"
nome = gets.chomp!

puts "Quanti anni hai?"
anni = gets.to_i

puts "Ciao, " + nome + " hai #{anni} anni"

unless (anni <= 18)
    puts "e sei maggiorenne."
else
    puts "e NON sei maggiorenne."
end
