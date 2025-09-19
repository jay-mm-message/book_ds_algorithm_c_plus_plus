clear

if [ -f "a.out" ]; then
	rm a.out
	echo "remove a.out"
fi

if [ "$1" == "" ]; then
	echo "Please type file name"
else
	g++ $1; ./a.out
fi