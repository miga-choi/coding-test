# Read from the file file.txt and output the tenth line to stdout.
sed -n 10p file.txt;


# Solution
# Solution 1
cnt=0
while read line && [ $cnt -le 10 ]; do let 'cnt = cnt + 1' if [ $cnt -eq 10 ]; then
    echo $line
    exit 0
  fi
done < file.txt

# Solution 2-1
awk 'FNR == 10 {print }'  file.txt

# Solution 2-2
awk 'NR == 10' file.txt

# Solution 3
sed -n 10p file.txt

# Solution 4
tail -n+10 file.txt|head -1
