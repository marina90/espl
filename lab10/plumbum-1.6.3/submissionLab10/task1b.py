import os
grades_file = open('lab10_grades.csv', "r")
error_file = open('codes_per_student.stats', "w")
for line in grades_file:
    #spliting the erro and reviewing them
    string_to_split = line.split('\t')
    string_to_split[1] = string_to_split[1].strip('\n')
    if string_to_split[1] == "":
        print "the student %s has 0 error" %(string_to_split[0])
        error_file.write("%s|0\n" %(string_to_split[0]))
    else :
        error_to_split = string_to_split[1].split('|')
        #writing to the file
        print "the student %s has %d error" %(string_to_split[0], len(error_to_split))
        error_file.write("%s|%d\n" %(string_to_split[0], len(error_to_split)))

# closing file
error_file.close()
grades_file.close
