
from plumbum.cmd import awk, wc, cat, sort, uinq
stream = ''
print "the student name are:"
first_command = awk["-F '|' '{print $1}' lab10_grades.csv"] | sort["-u"] #print the first line with names
first_command
print "the number of student is:"
os.system("awk -F '\t' '{print $1}' lab10_grades.csv | wc -l") #print the number of student
os.system("awk -F '\t' '{print $2}' lab10_grades.csv | awk -F '|*' '{print $1}' | awk -F '|' '{print $2}' lab10_grades.csv") #print the first line with names
