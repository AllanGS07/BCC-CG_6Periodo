FROM alpine:latest AS builder
RUN apk add --no-cache build-base

WORKDIR /app

COPY main.c .

RUN gcc -static main.c -o clipping

FROM alpine:latest

WORKDIR /app

COPY --from=builder /app/clipping .

CMD ["./clipping"]