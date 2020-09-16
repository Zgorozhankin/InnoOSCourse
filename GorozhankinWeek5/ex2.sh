#!bin/bash
echo 1 > ex2.txt

if [ -f ex2.lock ]
then
   rm ex2.lock
fi

while [ 1 ]
do

  while [ -f ex2.lock ]
  do
    sleep 1
  done

  ln ex2.sh ex2.lock

  end=$(tail -n 1 < ex2.txt)
  end=$((end+1))
  echo "$end" >> ex2.txt
  rm ex2.lock
done
