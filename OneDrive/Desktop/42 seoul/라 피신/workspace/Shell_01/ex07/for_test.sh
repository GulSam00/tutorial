cat /etc/passwd | sed '/#/d' | awk -F: '(NR % 2) == 0 {print $1}' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | awk 'ORS = ", " {print $0}' | sed 's/, $/./'
