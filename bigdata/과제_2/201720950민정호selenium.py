import os
import time
from selenium import webdriver

searchterm="강아지"

url = "https://www.google.com/search?q="+searchterm+"sourcelnms&tbm=isch"

browser = webdriver.Chrome(executable_path="chromedriver.exe")
browser.get(url)

for _ in range(2):
    browser.execute_script("window.scrollTo(0, document.body.scrollHeight):")
    time.sleep(2)
if not os.path.exists(searchterm):
    os.mkdir(searchterm)

succounter = 0

body = browser.find_element_by_id('islrg')
img_list = body.find_elements_by_tag_name('img')

for idx.value in enumerate(img_list):
    img_src = value.getattribute('src')
    print(img_src)
    try:
        save_path = os.path.join(searchterm, str(idx)+".png")
        print(save_path)

        value.screenshot(save_path)
        succounter = succounter +1
        
        runnung_test = "running: " + str(succounter) +" / " +str(len(img_list))
        print(running_test)
        
    except:
        print ("can't get img")

        

print (succounter, "succesfully downloaded")

browser.close()