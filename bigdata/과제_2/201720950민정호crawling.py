import requests
import time
import pandas as pd
from bs4 import BeautifulSoup

url = requests.get('https://www.yelp.com/search?find_desc=Restaurants&find_loc=Palo%20Alto%2C%20CA&start=0')
url
soup = BeautifulSoup(url.text,'html.parser')

whole_review=soup.findAll("a",attrs={"class":'css-166la90'})
whole_review

restaurant_list=list()
for line in whole_review:
    text=line.get_text()
    restaurant_list.append(text)

restaurant_list=restaurant_list[0:10]
print(restaurant_list)

whole_review = soup.findAll("div", attrs={"class":"i-stars__09f24__1T6rz"})
whole_review

rating_list=list()

for line in whole_review:
    text = str(line.attrs['aria-label'])
    text = text.replace('star rating','')
    rating_list.append(text)

rating_list

multi_page_result=list()
for idx, value in enumerate(restaurant_list):
    row_data=[restaurant_list[idx],rating_list[idx]]
    multi_page_result.append(row_data)
multi_page_result
multi_page_result = pd.DataFrame(multi_page_result, columns=['Restaurant_name','rating'])