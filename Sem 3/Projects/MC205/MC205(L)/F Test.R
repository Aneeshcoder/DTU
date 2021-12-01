#Fisher's F - Test

#Code I
x1 <- rnorm(249, mean = 20)
y1 <- rnorm(79, mean = 30)

#Performing F Test
var.test(x1, y1, alternative = "two.sided")


#Code II
x2 = c(25, 29, 35, 46, 58, 66, 68)
y2 = c(14, 16, 24, 28, 32, 35,
       37, 42, 43, 45, 47)

#Performing F Test
var.test(x2, y2)