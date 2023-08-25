To run the bash script, first install expect:

apt-get install expect

commands:

(to run all inputs in input_random.txt on program)

./try.sh > out.txt

(extract encoded strings from out.txt to output.txt)

g++ extract.cpp

./a.out

(convert encoded strings in output.txt to binary in binary_output.txt)

g++ converter.cpp

./a.out
