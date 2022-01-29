FROM ubuntu

WORKDIR /home/ssl

RUN apt-get -y update && \
    apt -y install build-essential && \
    apt -y install flex && \
    apt -y install bison && \
    rm -rf /var/lib/apt/lists/*