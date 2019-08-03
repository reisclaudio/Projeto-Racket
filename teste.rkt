 #lang racket

;;Abre o arquivo .geo
(define geo (open-output-file "teste.geo"))

(define (gerarId string numero)
  (string-append string (number->string numero)))

(define (gerarQuadras x y i contadorQuadras)
  (cond [(equal? contadorQuadras 25) 
            (display (string-append "q " (gerarId "quadra" contadorQuadras) " " (number->string x) " " (number->string y) " 120 80\n") geo)]

        [(equal? i 5) 
            (display (string-append "q " (gerarId "quadra" contadorQuadras) " " (number->string x) " " (number->string y) " 120 80\n") geo) 
            (gerarQuadras 25 (+ y 95) 0 (+ contadorQuadras 1))]

        [#t 
            (display (string-append "q " (gerarId "quadra" contadorQuadras) " " (number->string x) " " (number->string y) " 120 80\n") geo) 
            (gerarQuadras (+ x 135) y (+ i 1) (+ contadorQuadras 1))])) 