#T - Test

#One Sample T Test
df1 <- c(rnorm(50, mean = 140, sd = 5))

#Performing T Test
t.test(df1, mu = 150) # Ho: mu = 150


#Two sample T Test
df21 <- rnorm(50, mean = 140, sd = 4.5)
df22 <- rnorm(50, mean = 150, sd = 4)

#Performing T Test
t.test(df21, df22, var.equal = TRUE)


#Paired Sample T Test
df31 <- c(rnorm(100, mean = 14, sd = 0.3))
df32 <- c(rnorm(100, mean = 13, sd = 0.2))

#Performing T Test
t.test(df31, df32, paired = TRUE)
