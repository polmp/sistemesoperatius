clear
reset
unset key
# Make the x axis labels easier to read.
set xtics rotate out
# Select histogram data
set style data histogram
# Give the bars a plain fill pattern, and draw a solid line around them.
set style fill solid border
set boxwidth 0.95 relative
set style histogram rowstacked
set offsets graph -0.1,-0.5, 0, 0
plot 'data.dat' using 2:xticlabel(1) lt rgb "#66FF66"
set xlabel "Agrupacions"
set ylabel "Vots (percentatge)"

