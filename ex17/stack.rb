stack = []

puts "DEBUG: push 5 values onto the stack"
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
stack.push(5)

puts "DEBUG: print the stack"
puts stack.join(', ')

puts "DEBUG: pop a value from the end of the stack and print it"
puts stack.pop()

puts "DEBUG: pop a value from the end of the stack and print it"
puts stack.pop()

puts "DEBUG: print the stack after all"
puts stack.join(', ')
