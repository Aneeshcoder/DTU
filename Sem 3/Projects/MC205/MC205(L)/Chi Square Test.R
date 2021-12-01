#Chi Square Test for Independence

#Code I
#Creating Data table
data_ = cbind(x=c(12,23,26,17,9,45),y=c(34,25,41,19,53,33))
data_ = data.frame(data_)
data_ = table(data_)

#Showing data table
data_

#Performing Chi Square Test
chisq.test(data_) 


#Code II
#Creating Data table
df = data.frame(rnorm(10),rnorm(10))
df = table(df)

#Showing data table
df

#Performing Chi Square Test
chisq.test(df)
