from plumbum.cmd import awk, wc, cat, sort, uniq, sed
print "the student name are:"
first_command = awk["-F",  "\t", "{print $1}", "lab10_grades.csv"] | sort["-u"] #print the first line with names
print first_command()
print "the number of student is:"
second_command = awk["-F" ,"\t", "{print $1}" ,"lab10_grades.csv"]|wc["-w"] #print the number of student
print second_command()
print "the error code are:"
third_command = (awk["-F" ,"\t", "{print $2}" ,"lab10_grades.csv"] | sed['s/|/\\n/g'] | sort["-u"])() #print the error
print third_command
print "number of unique error-codes found in the file:"
forth_command = (awk["-F" ,"\t", "{print $2}" ,"lab10_grades.csv"] | sed['s/|/\\n/g'] | sort["-u"] | wc["-w"])() #print the number of error
print forth_command


