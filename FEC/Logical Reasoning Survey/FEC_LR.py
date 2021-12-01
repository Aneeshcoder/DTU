import warnings
warnings.filterwarnings('ignore')

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns 
import plotly.express as px

df = pd.read_csv('https://raw.githubusercontent.com/Aneeshcoder/FEC_LR_DTU_Sem_II/main/Logical%20Reasoning%20Survey.csv')
df.head()

df.info()

sns.countplot(df['Your age group ?'], label="count",);

plt.figure(figsize=(15,8))
sns.countplot(df['Approach you used to find the solution to that question ?'], label="count",);

plt.figure(figsize=(150,100))
sns.countplot(df['why you choose that particular method ?'], label="count",);

fig = px.pie(df['Your age group ?'],names='Your age group ?')
fig.show(renderer='colab')

fig = px.pie(df['Approach you used to find the solution to that question ?'],names='Approach you used to find the solution to that question ?')
fig.show(renderer='colab')

fig = px.pie(df['why you choose that particular method ?'],names='why you choose that particular method ?')
fig.show(renderer='colab')

fig = px.scatter(df, x="Your age group ?", y="Approach you used to find the solution to that question ?")
fig.show()

fig = px.histogram(df, x="why you choose that particular method ?", 
                   y="Approach you used to find the solution to that question ?", 
                   color="Your age group ?")
fig.show()

