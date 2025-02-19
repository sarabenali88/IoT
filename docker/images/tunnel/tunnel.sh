#!/bin/bash

# PHP creates a simple REST-server on port 8000 where we make the /tmp directory available.
php -S 0.0.0.0:8000 -t /tmp &

# Tunnels the traffic from our nginx-docker container to the localtunnel server. Writes the output to a file.
while true
do
lt --local-host nginx --port $1 --subdomain $2 > /tmp/localtunnel
sleep 5
done