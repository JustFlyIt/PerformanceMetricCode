#Run LMBench3 tests
#Jason Harnish -  7-17-2018   Initial Creation
#Don Snyder -     5-7-2019    Updated to support lmbench3
#Northrop Grumman Corp.

#See MAN page for bw_mem command in LMbench3 for details

types="rdwr rd wr cp frd fwr fcp bzero bcopy"
sizes="1k 2k 4k 8k 16k 32k 64k 128k 256k 512k 1M 2M 4M 8M 16M 32M 64M"
logfile="/var/log/lmbench3.log"
csvfile="/tmp/lmbench3.`hostname`.`date +%m-%d-%y_%H:%M:%S`.csv"

for type in $types; do
	echo Running LMBench3 $type Tests...
	for size in $sizes; do
		/tmp/lmbench3/bin/linux-arm/bw_mem -P 8 $size $type &>> $logfile_$type
	done
	echo Processing into CSV format...
	cat $logfile_$type | sed 's/ /,/'|  sed "s/./$type,&/" >> $csvfile
	rm -f $logfile_$type
done
echo Done.
echo CSV written to $csvfile
