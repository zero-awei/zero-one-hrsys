FROM openjdk:8
ENV SENTINEL_HOME /home/sentinel-dashboard
RUN mkdir -p ${SENTINEL_HOME}
COPY sentinel-dashboard-1.8.1.jar ${SENTINEL_HOME}/sentinel-dashboard.jar
RUN chmod -R +x ${SENTINEL_HOME}/*jar
WORKDIR ${SENTINEL_HOME}
EXPOSE 8080
CMD java ${JAVA_OPTS} -jar sentinel-dashboard.jar