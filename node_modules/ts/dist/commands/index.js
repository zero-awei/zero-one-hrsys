"use strict";
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
var build = __importStar(require("./build"));
exports.build = build;
var search = __importStar(require("./search"));
exports.search = search;
// Just an alias
var compile = build;
exports.compile = compile;
