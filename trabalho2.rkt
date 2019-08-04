#lang racket

;; Abre o arquivo .geo
(define geo (open-output-file "b1.geo"))
(define geo2 (open-output-file "b2.geo"))
(define geo3 (open-output-file "b3.geo"))



;; Recebe uma string e um numero a string de ambos concatenados
(define (gerarId string numero)
    (string-append string (number->string numero)))



(define (gerarElementos tamanhoCidade x y w h i contadorQuadras contadorHidrantes contadorRadiosBase boleanoSemaforo)
    (cond
        [(equal? boleanoSemaforo 0)
           (imprimeSemaforos tamanhoCidade (+ x 127.5) (+ y 87.5) 0 0)
           (gerarElementos tamanhoCidade x y w h i contadorQuadras contadorHidrantes contadorRadiosBase 1)]

        [(equal? contadorQuadras(- (* tamanhoCidade tamanhoCidade) 1))
           (imprimeQuadras x y w h contadorQuadras)
           (imprimeHidrantes x y contadorHidrantes)
           (imprimeRadiosBase x y contadorRadiosBase)]

        [(equal? i (- tamanhoCidade 1))
           (imprimeQuadras x y w h contadorQuadras)
           (imprimeHidrantes x y contadorHidrantes)
           (cond [(equal? (remainder contadorQuadras 2) 0) (imprimeRadiosBase x y contadorRadiosBase)])
           (gerarElementos tamanhoCidade 25 (+ y 95) w h 0 (+ contadorQuadras 1) (+ contadorHidrantes 1) (+ contadorRadiosBase 1) 1)]

        [#t
           (imprimeQuadras x y w h contadorQuadras)
           (imprimeHidrantes x y contadorHidrantes)
           (cond [(equal? (remainder contadorQuadras 2) 0) (+ 1 contadorRadiosBase) (imprimeRadiosBase x y contadorRadiosBase)])
           (gerarElementos tamanhoCidade (+ x 135) y w h (+ i 1) (+ contadorQuadras 1) (+ contadorHidrantes 1) (+ contadorRadiosBase 1) 1)]))



(define (imprimeQuadras x y w h id)
    (display (string-append "q " (gerarId "quadra" id) " " (number->string x) " " (number->string y) " " (number->string w) " " (number->string h) "\n") geo))



(define (imprimeHidrantes x y id)
    (display (string-append "h " (gerarId "hidrante" id) ".1" " " (number->string (+ x 60)) " " (number->string y) "\n") geo)
    (display (string-append "h " (gerarId "hidrante" id) ".2" " " (number->string (+ x 120)) " " (number->string (+ y 40)) "\n") geo)
    (display (string-append "h " (gerarId "hidrante" id) ".3" " " (number->string (+ x 60)) " " (number->string (+ y 80)) "\n") geo)
    (display (string-append "h " (gerarId "hidrante" id) ".4" " " (number->string x) " " (number->string (+ y 40)) "\n") geo))



(define(imprimeRadiosBase x y id)
    (display (string-append "rb " (gerarId "radioBase" id) " " (number->string (+ x 60)) " " (number->string (+ y 40)) "\n") geo))



(define(imprimeSemaforos tamanhoCidade x y i contadorSemaforos)
    (cond
        [(equal? contadorSemaforos (* (- tamanhoCidade 1) (- tamanhoCidade 1)))
           (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") geo)]

        [(equal? i (- tamanhoCidade 2))
           (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") geo)
           (imprimeSemaforos tamanhoCidade 152.5 (+ y 95) 0 (+ contadorSemaforos 1))]

        [#t
           (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") geo)
           (imprimeSemaforos tamanhoCidade (+ x 135) y (+ i 1) (+ contadorSemaforos 1))]))


;; Bloco de codigo piloto
(gerarElementos 5 25 25 120 80 0 0 0 0 0)
(close-output-port geo)
(close-output-port geo2)
(close-output-port geo3)


           