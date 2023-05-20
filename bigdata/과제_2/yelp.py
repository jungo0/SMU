#!/usr/bin/env python
# coding: utf-8

# In[ ]:


get_ipython().system('pip3 install bs4 requests pandas')


# In[1]:


import requests
import time
import pandas as pd
from bs4 import BeautifulSoup


# In[2]:


#맨 끝의 start=0을 10으로 바꾸면 다음 페이지의 음식점 리스트를 받아올 수 있음
url = requests.get('https://www.yelp.com/search?find_desc=Restaurants&find_loc=Palo+Alto%2C+CA&ns=1&start=0')
#url = 'requests.get(https://www.yelp.com/search?find_desc=Dumplings&find_loc=Koreatown%2C%20Los%20Angeles%2C%20CA')


# In[3]:


url


# In[4]:


soup = BeautifulSoup(url.text,'html.parser')


# In[5]:


soup


# In[6]:


whole_review = soup.findAll("a", attrs={"class":"css-166la90"})


# In[7]:


whole_review


# In[8]:


restaurant_list = list()
for line in whole_review:
    text = line.get_text()
    restaurant_list.append(text)


# In[9]:


restaurant_list


# In[10]:


restaurant_list = restaurant_list[0:10]
print(restaurant_list)


# In[11]:


whole_review = soup.findAll("div", attrs={"class":"i-stars__09f24__1T6rz"})


# In[12]:


whole_review


# In[13]:


rating_list = list()

for line in whole_review:
    text = str(line.attrs['aria-label'])
    text = text.replace(' star rating','')
    rating_list.append(text)


# In[14]:


rating_list


# In[15]:


multi_page_result= list()
for idx, value in enumerate(restaurant_list):
    row_data = [restaurant_list[idx], rating_list[idx]]
    multi_page_result.append(row_data)


# In[16]:


multi_page_result


# In[19]:


multi_page_result = pd.DataFrame(multi_page_result, columns=['Restaurant_name', 'rating'])
multi_page_result


# In[18]:


multi_page_result.to_csv('yelp.csv')


# # Q. review 카운트를 dataframe에 추가하고 csv 파일로 저장하세요(같이 제출)
