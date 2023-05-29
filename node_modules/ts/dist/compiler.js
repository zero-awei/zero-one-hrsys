"use strict";
var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var typescript_1 = __importDefault(require("typescript"));
function loadCustomTransformations(options) {
    if (!options.transformations) {
        return [];
    }
    return options.transformations.map(function (modulePath) {
        var module = require(modulePath);
        var transformer = module && module.default ? module.default : module;
        return transformer;
    });
}
function compileOnce(filePaths, compilerOptions, options) {
    var customTransformations = loadCustomTransformations(options);
    var program = typescript_1.default.createProgram(filePaths, __assign({}, compilerOptions, { noEmit: false, noEmitOnError: true }));
    var transformations = {
        before: customTransformations.map(function (transformation) { return transformation({}, program); })
    };
    var result = program.emit(undefined, undefined, undefined, undefined, transformations);
    var diagnostics = typescript_1.default.getPreEmitDiagnostics(program).concat(result.diagnostics);
    return {
        diagnostics: diagnostics,
        result: result
    };
}
exports.compileOnce = compileOnce;
