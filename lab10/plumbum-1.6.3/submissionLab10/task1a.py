import os
grades_file = open('lab10_grades.csv', "r")
error_file = open('errorcodes.stats', "w")
error_list= []
for line in grades_file:
    #spliting the erro and reviewing them
    string_to_split = line.split('\t')
    string_to_split[1] = string_to_split[1].strip('\n')
    error_to_split = string_to_split[1].split('|')
    error_list = error_list + error_to_split

# writing the statistic

for error in set(error_list):
    if error:
        print "the error %s reapet %d" %(error, error_list.count(error))
        error_file.write("%s|%d\n" %(error, error_list.count(error)))
# closing file
error_file.close()
grades_file.close
