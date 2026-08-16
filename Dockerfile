FROM gcc:12-bullseye

WORKDIR /app

COPY main.cpp Makefile ./
RUN make

CMD ["./main"]
