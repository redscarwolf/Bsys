# $Date: $
# $Rev: $
# $Author: $
reset
set title 'Abweichung gemessene aktive Wartezeit zur angestrebten Wartezeit'
# get the difference between the two values
set table "deviation.dat"
plot "< sort -n rand_t.dat" u 1:((($2-$1)/$1)*100)
y_min = GPVAL_DATA_Y_MIN
y_max = GPVAL_DATA_Y_MAX
x_min = GPVAL_DATA_X_MIN
x_max = GPVAL_DATA_X_MAX
x_len = x_max-x_min
unset table
print "Maximal deviation: ", y_max, "%"
print "Minimal deviation: ", y_min, "%"
# plot
unset key
set term post eps size 18.0,12.0 enhanced color lw 2 font ",20"
set output "statistic.eps"
set yrange [y_min-1:y_max+1]
set xrange [x_min-(x_len*0.05):x_max+(x_len*0.05)]
# The labels
set ylabel "Abweichung [%]"
set xlabel "Wartezeiten "
set data style points
set xtics 2
set ytics 1

# Plotting the minimum and maximum ranges with a shaded background
plot y_min with filledcurves y1=0 lt 1 lc rgb "#ddbbdd", \
y_max with filledcurves y1=0 lt 1 lc rgb "#bbddbb", \
'deviation.dat' u 1:2 w l lt 1 lw 2.5 notitle, \
'deviation.dat' u 1:2 w p pt 4 ps 2 notitle
