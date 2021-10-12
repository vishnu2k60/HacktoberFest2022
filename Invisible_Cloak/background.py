import cv2
#print(cv2.__version__)
cap = cv2.VideoCapture(0)
while cap.isOpened():
    ret,bg = cap.read()
    if ret:
        cv2.imshow("image",bg)
        if cv2.waitKey(5)==ord('q'):
            cv2.imwrite('image.jpg',bg)
            break
cap.release()
cv2.destroyAllWindows()