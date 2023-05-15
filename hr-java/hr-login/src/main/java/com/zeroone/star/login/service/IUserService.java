package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.User;

/**
 * @author 风月
 * @date 2023/5/15 10:00
 */
public interface IUserService extends IService<User> {

    /***
     /获取当前用户的密码（用于判断和新密码是否一致）
     * @param username
     * @return 当前密码
     */
    String getCurrentPassword(String username);


    /***
     * 修改密码
     * @param username
     * @param password
     * @return 是否修改成功
     */
    Boolean updatePassword(String username, String password);
}
