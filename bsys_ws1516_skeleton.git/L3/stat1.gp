# $Date: $
# $Rev: $
# $Author: $
reset
plot "rand_t.dat" u 1:2 #To get the max and min value
ymax=GPVAL_DATA_Y_MAX
ymin=GPVAL_DATA_Y_MIN
ylen=ymax-ymin
xmax=GPVAL_DATA_X_MAX
xmin=GPVAL_DATA_X_MIN
print "Maximal measured time value: ", ymax
print "Minimal measured time value: ", ymin
#plot
set term post eps size 18.0,12.0 enhanced color lw 2 font ",20"
set output "statistic.eps"
set xrange [0:xmax]
set yrange [0:ymax+(0.2*ylen)]
set xlabel "Desired time"
set ylabel "Measured time"
set xtics 2.5
set ytics 2.5
#The labels
plot "rand_t.dat" u 1:2 w p pt 7 ps 2 notitle,\
     x
