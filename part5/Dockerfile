FROM nginx:1.27.0

RUN apt-get update && apt-get install -y \
    build-essential \
    libfcgi-dev \
    spawn-fcgi \
    && rm -rf /var/lib/apt/lists/*

COPY hello_world.c /app/hello_world.c
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

RUN gcc -o /app/hello_world /app/hello_world.c -lfcgi

RUN echo '#!/bin/bash\n\
spawn-fcgi -p 8080 -n /app/hello_world &\n\
nginx -g "daemon off;"' > /start.sh && chmod +x /start.sh

RUN useradd -m clifforc

RUN chown -R clifforc:clifforc /app /var/cache/nginx /var/log/nginx /etc/nginx

USER clifforc

ENTRYPOINT ["/start.sh"]
