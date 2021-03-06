import cv2                         #image processing
import requests as r              #image send online
import io                          #bytes conversion
import json  #CONVERT OUTPUT FROM STR TO DICTIONARY
import numpy as np
import pyttsx3 #SPEECH

cap=cv2.VideoCapture(0)
while(True):    #For capturing the Image
    ret,frame=cap.read()
    cv2.imshow('karan',frame)
    if cv2.waitKey(1) == ord('a'):
        cv2.imwrite('thakur.jpg',frame)
        url_api = "https://api.ocr.space/parse/image"
        a = cv2.imread("thakur.jpg")
        _, compressed = cv2.imencode(".jpg", a, [1, 90])  # COMPRESSED IMAGE
        file_bytes = io.BytesIO(compressed)
        result = r.post(url_api,         # SEND TO OCRAPI
                        files={"thakur.jpg": file_bytes},
                        data={"apikey": "uSE YOURS FROM SIGNUP OCR SPACE"})
        result = result.content.decode()  # RECEIVED STR
        result = json.loads(result)  # CONVERTING STR TO DICTIONARY
        detect = result.get("ParsedResults")[0].get("ParsedText")
        print(detect)
        speak = detect   # SPEAK
        engine1 = pyttsx3.init()
        engine1.say(speak)
        engine1.runAndWait()
        break
cap.release()
cv2.destroyAllWindows()
engine = pyttsx3.init()
engine.say("THANKS...DO..YOU..WANT..TO..CONTINUE")
engine.runAndWait()

