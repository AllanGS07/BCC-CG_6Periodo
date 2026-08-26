FROM alpine:latest AS builder
RUN apk add --no-cache build-base

WORKDIR /app

COPY Cohen-Sutherland.c .

RUN gcc -static Cohen-Sutherland.c -o clipping


# --------------------------------------------
FROM alpine:latest

WORKDIR /app

COPY --from=builder /app/clipping .

CMD ["./clipping"]