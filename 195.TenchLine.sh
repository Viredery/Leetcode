# Read from the file file.txt and output the tenth line to stdout.
num=1
cat file.txt | while read line
do
    if [ $num -eq 10 ]
    then
        echo $line
        exit 0
    else
        num=$[num+1]
    fi
done

