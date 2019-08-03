#lang racket

;;Abre o arquivo .geo
(define geo (open-output-file "teste.geo"))

(define (gerarId string numero)
  (string-append string (number->string numero)))

(define (gerarQuadras contadorQuadras)
  (cond [#t (display "q\n" geo)]))
        ;;[#t (gerarQuadras (+ contadorQuadras 1))]))
        ;;[#t gerarQuadras (+ x 135) y (+ i 1) (+ contadorQuadras 1)]))


(close-output-port geo)