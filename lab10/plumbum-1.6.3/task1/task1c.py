grades_file = open('lab10_grades.csv', "r")
error_file = open('errorcodes.stats', "w")
error_list= []
for line in grades_file:
    #spliting the erro and reviewing them
    string_to_split = line.split('\t')
    string_to_split[1] = string_to_split[1].strip('\n')
    error_to_split = string_to_split[1].split('|')
    error_list = error_list + error_to_split

# writing the statistic, computing the error
max_error = 0
min_error = 100
for error in set(error_list):
    if error:
        print "the error %s reapet %d" %(error, error_list.count(error))
        error_file.write("%s|%d\n" %(error, error_list.count(error)))
        max_error = max(max_error, error_list.count(error))
        min_error = min(min_error, error_list.count(error))


print "the minimum error is %d" %(min_error)
print "the maximum error is %d" %(max_error)

# computhin the error per student
student_error = open('codes_per_student.stats', "r")
max_error = 0
min_error = 100
number_of_error = []
for line in student_error:
    string_to_split = line.split('|')
    max_error = max(max_error, int(string_to_split[1]))
    min_error = min(min_error, int(string_to_split[1]))
    number_of_error.append(string_to_split[1])

print "the minimum error  a student has is %d" %(min_error)
print "the maximum error a student has is %d" %(max_error)

#calculate the median
number_of_error.sort()
list_length = len(number_of_error)
if list_length%2 == 0:
    median = (list_length/2 + (list_length/2 +1))/2
    print "the median is %d" %(int(number_of_error[median]))
else:
    median = list_length/2
    print "the median is %d" %(int(number_of_error[median]))

# closing file

error_file.close()
grades_file.close
