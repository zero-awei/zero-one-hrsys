package com.zeroone.star.ws.service;

import cn.hutool.json.JSONUtil;
import lombok.SneakyThrows;
import org.springframework.stereotype.Component;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.util.concurrent.ConcurrentHashMap;

/**
 * <p>
 * 描述：聊天室
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
@ServerEndpoint("/chat")
public class ChatServer {
    /**
     * 定义一个连接对象池
     */
    private static ConcurrentHashMap<String, Session> SESSION_POOL = new ConcurrentHashMap<>();

    @SneakyThrows
    @OnOpen
    public void onOpen(Session session) {
        // 判断连接对象使用唯一编号是否存在
        String id = session.getQueryString();
        if (SESSION_POOL.containsKey(id)) {
            CloseReason closeReason = new CloseReason(CloseReason.CloseCodes.CANNOT_ACCEPT, "ID冲突，连接拒绝");
            session.getUserProperties().put("reason", closeReason);
            session.close();
            return;
        }

        // 存放到连接池里面
        SESSION_POOL.put(id, session);
        System.out.println("客户端{" + id + "}：开启连接");
    }

    @OnClose
    public void onClose(Session session) {
        String id = session.getQueryString();
        // 处理拒绝连接
        Object reason = session.getUserProperties().get("reason");
        if (reason instanceof CloseReason) {
            CloseReason closeReason = (CloseReason) reason;
            if (closeReason.getCloseCode() == CloseReason.CloseCodes.CANNOT_ACCEPT) {
                System.out.println("客户端{" + id + "}：连接被拒绝");
                return;
            }
        }

        // 从连接池中移除掉连接对象
        SESSION_POOL.remove(id);
        System.out.println("客户端{" + id + "}：关闭连接");
    }

    @SneakyThrows
    @OnMessage
    public String onMessage(String text, Session session) {
        // 消息格式要求 ==> ID::消息内容
        String[] msgs = text.split("::", 2);

        //群发
        if ("all".equals(msgs[0])) {
            for (Session sub : SESSION_POOL.values()) {
                // 排除自己
                if (sub == session) {
                    continue;
                }
                // 发送消息
                sub.getBasicRemote().sendText(msgs[1]);
            }
        }
        //指定发送
        else {
            Session target = SESSION_POOL.get(msgs[0]);
            if (target != null) {
                target.getBasicRemote().sendText(msgs[1]);
            }
        }
        return session.getQueryString() + "：消息发送成功";
    }

    /**
     * 发送消息
     * @param id      用户编号
     * @param message 消息内容
     */
    @SneakyThrows
    public void sendMessage(String id, Object message) {
        //群发
        if ("all".equals(id)) {
            for (Session sub : SESSION_POOL.values()) {
                // 发送消息
                sub.getBasicRemote().sendText(JSONUtil.toJsonStr(message));
            }
        }
        //指定发送
        else {
            Session target = SESSION_POOL.get(id);
            if (target != null) {
                target.getBasicRemote().sendText(JSONUtil.toJsonStr(message));
            }
        }
    }
}
