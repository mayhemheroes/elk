FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo
RUN clang -fsanitize=fuzzer mayhem/fuzz_js_eval.c elk.c -I../.. -o fuzz_js_eval -lm -DJS_DUMP=1

FROM ubuntu:20.04 as package
COPY --from=builder /repo/fuzz_js_eval /
