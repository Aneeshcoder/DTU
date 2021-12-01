#ANalysis Of VAriance (ANOVA) Test

#One Way ANOVA Test
#Creating Data
dt<-data.frame(id=c(1:10), name=c('a','b','c','d','e','f','g','h','i','j'),
               income=c(100,150,125,200,230,260,250,330,230,400), 
               age=c(23,25,24,26,27,29,32,21,30,31),
               stringsAsFactors=FALSE)

#Performing ANOVA Test
one.way<-aov(income~age, data=dt) 
one.way	

#Showing outcome of ANOVA Test
summary(one.way)


#Two Way ANOVA Test
#Creating Data
dt<-data.frame(id=c(1:10), name=c('a','b','c','d','e','f','g','h','i','j'), 
               income=c(100,150,125,200,230,260,250,330,230,400), 
               age=c(23,25,24,26,27,29,32,21,30,31),
               stringsAsFactors=FALSE)

#Performing for ANOVA Test for specific variables
two.way<-aov(dt$id~dt$income+dt$age, data=dt) 
two.way

#Showing outcome of ANOVA Test
summary(two.way)

#Performing ANOVA Test as Two way
two.way2<-aov(dt$id~dt$income*dt$age, data=dt)
two.way2<-aov(dt$id~dt$income+dt$age + income:age, data=dt)

#Showing outcome of ANOVA Test
summary(two.way2)
