package io.github.bluemiaomiao.factory;

import org.apache.commons.pool2.PooledObject;
import org.apache.commons.pool2.PooledObjectFactory;
import org.apache.commons.pool2.impl.DefaultPooledObject;
import org.csource.fastdfs.StorageClient;
import org.csource.fastdfs.TrackerClient;
import org.csource.fastdfs.TrackerServer;

// 用于创建连接对象的工厂类
public class StorageClientFactory implements PooledObjectFactory<StorageClient> {

    @Override
    public PooledObject<StorageClient> makeObject() throws Exception {
        TrackerClient client = new TrackerClient();
        TrackerServer server = client.getConnection();
        return new DefaultPooledObject<>(new StorageClient(server, null));
    }

    @Override
    public void destroyObject(PooledObject<StorageClient> p) throws Exception {
        p.getObject().getTrackerServer().close();
    }

    @Override
    public boolean validateObject(PooledObject<StorageClient> p) {
        return false;
    }

    @Override
    public void activateObject(PooledObject<StorageClient> p) throws Exception {

    }

    @Override
    public void passivateObject(PooledObject<StorageClient> p) throws Exception {

    }
}
