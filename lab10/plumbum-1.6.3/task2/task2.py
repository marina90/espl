grades_file = open('lab10_grades.csv', "r")
point_to_reduce_file = open('error-codes.txt', "r")
error_file = open(' final_grades.stats', "w")
error_list= []

grades_table = {} #this is a diconary
for line in point_to_reduce_file:
    grade_to_split = line.split('\t')
    grade_to_split[1] = grade_to_split[1].strip('\n')
    grades_table[grade_to_split[0]] = grade_to_split[1]

point_to_reduce_file.close()

for line in grades_file:
    #spliting the erro and reviewing them
    student_grade = 100
    string_to_split = line.split('\t')
    string_to_split[1] = string_to_split[1].strip('\n')
    error_to_split = string_to_split[1].split('|')
    error_list = error_list + error_to_split

    #now calculate the grades
    for index in range(len(error_to_split)):
        if string_to_split[1] != "":
            student_grade = student_grade - (int(grades_table[error_to_split[index]]))


    print "the student %s final grade is %d" %(string_to_split[0],student_grade)
    error_file.write("%s|%d\n" %(string_to_split[0], student_grade))

# closing file
error_file.close()
grades_file.close
