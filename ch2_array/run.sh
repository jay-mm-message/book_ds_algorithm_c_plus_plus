clear

if [ -f "a.out" ]; then
	rm a.out
	echo "remove a.out"
fi

g++ $1; ./a.out