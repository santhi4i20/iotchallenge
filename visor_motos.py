import cv2

# Carrega imagem
imagem = cv2.imread("patio.jpg")

# Converte para escala de cinza
cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)

# Classificador Haar para motos (pode ser genérico)
detector = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_motorcycle.xml")

# Detecção
motos = detector.detectMultiScale(cinza, scaleFactor=1.1, minNeighbors=3)

# Desenha os retângulos
for (x, y, w, h) in motos:
    cv2.rectangle(imagem, (x, y), (x+w, y+h), (0, 255, 0), 2)

# Exibe resultado
cv2.imshow("Detecção de Motos", imagem)
cv2.waitKey(0)
cv2.destroyAllWindows()
