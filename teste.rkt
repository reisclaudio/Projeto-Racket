#lang racket

;; Abre o arquivo .geo
(define geo (open-output-file "teste.geo"))



;; Recebe uma string e um numero a string de ambos concatenados
(define (gerarId string numero)
    (string-append string (number->string numero)))



(define (gerarElementos x y w h i contadorQuadras contadorHidrantes)
    (cond
        [(equal? contadorQuadras 24)
           (imprimeQuadras x y w h contadorQuadras)
           (imprimeHidrantes x y contadorHidrantes)]
         

        [(equal? i 4)
           (imprimeQuadras x y w h contadorQuadras)
           (imprimeHidrantes x y contadorHidrantes)
           (gerarElementos 25 (+ y 95) w h 0 (+ contadorQuadras 1) (+ contadorHidrantes 1))]

        [#t
           (imprimeQuadras x y w h contadorQuadras)
           (imprimeHidrantes x y contadorHidrantes)
           (gerarElementos (+ x 135) y w h (+ i 1) (+ contadorQuadras 1) (+ contadorHidrantes 1))]))



(define (imprimeQuadras x y w h id)
    (display (string-append "q " (gerarId "quadra" id) " " (number->string x) " " (number->string y) " " (number->string w) " " (number->string h) "\n") geo))



(define (imprimeHidrantes x y id)
    (display (string-append "h " (gerarId "hidrante" id) ".1" " " (number->string (+ x 60)) " " (number->string y) "\n") geo)
    (display (string-append "h " (gerarId "hidrante" id) ".2" " " (number->string (+ x 120)) " " (number->string (+ y 40)) "\n") geo)
    (display (string-append "h " (gerarId "hidrante" id) ".3" " " (number->string (+ x 60)) " " (number->string (+ y 80)) "\n") geo)
    (display (string-append "h " (gerarId "hidrante" id) ".4" " " (number->string x) " " (number->string (+ y 40)) "\n") geo))


    