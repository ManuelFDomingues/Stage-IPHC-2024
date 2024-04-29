cd "/adhome/m/md/m.domingues/Bureau/Logiciel/data"


set terminal gif animate delay 1 loop 0 optimize size 600,400
set output '../programs/visuels/output.gif'
set pointsize 3
stats 'muon' using 2 name "x" nooutput
stats 'muon' using 3 name "y" nooutput
stats 'muon' using 4 name "z" nooutput
stats 'muon' nooutput
ntail = STATS_records

do for [ii=1:STATS_records] {
    title = sprintf ("Temps = %d",ii)
    im = ((ii-ntail) < 0 ? 1:ii-ntail)
    set title title
    splot [x_min:x_max][y_min:y_max][z_min:z_max] 'muon' using 2:3:4 every ::ii::ii with points pointtype 6 lc rgb "blue",\
    'muon' using 2:3:4 every ::im::ii with lines lw 2 lt 1 lc rgb "#1E90FF"
    }

