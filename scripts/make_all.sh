for dir in $2
do
  make -C $dir $1 $3;
  if [ $? != 0 ];
    then exit 1;
  fi;
done