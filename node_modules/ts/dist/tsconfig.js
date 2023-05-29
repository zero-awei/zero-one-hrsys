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
var sources_1 = require("./sources");
var tsconfigDefaults = {
    options: {
        esModuleInterop: true,
        lib: ["es2015"],
        newLine: "lf",
        module: "commonjs",
        moduleResolution: "node",
        outDir: "dist/",
        strict: true,
        target: "es5"
    }
};
var dedupe = function (array) { return Array.from(new Set(array)); };
function getCompilerOptions(cliFlags, options, packageJsonData, tsconfigJsonData) {
    if (tsconfigJsonData === void 0) { tsconfigJsonData = null; }
    var packageJsonConfig = packageJsonData.ts || {};
    var tsconfigJson = __assign({ compilerOptions: {} }, tsconfigJsonData);
    var compilerOptions = __assign({}, tsconfigDefaults.options, tsconfigJson.compilerOptions, (packageJsonConfig.compilerOptions || {}));
    if (cliFlags.declaration) {
        compilerOptions.declaration = true;
    }
    if (cliFlags.jsx) {
        compilerOptions.jsx = cliFlags.jsx;
    }
    if (cliFlags.lib) {
        compilerOptions.lib = cliFlags.lib.split(",");
    }
    if (cliFlags.noStrict) {
        compilerOptions.strict = false;
    }
    if (cliFlags.outDir) {
        compilerOptions.outDir = cliFlags.outDir;
    }
    if (cliFlags.outModule) {
        compilerOptions.module = cliFlags.outModule;
    }
    if (cliFlags.rootDir) {
        compilerOptions.rootDir = cliFlags.rootDir;
    }
    if (cliFlags.skipLibCheck) {
        compilerOptions.skipLibCheck = true;
    }
    if (cliFlags.sourceMaps) {
        compilerOptions.sourceMap = true;
    }
    if (cliFlags.target) {
        compilerOptions.target = cliFlags.target;
    }
    if (options.monorepo) {
        compilerOptions.paths = __assign({}, compilerOptions.paths, { "*": dedupe((compilerOptions.paths && compilerOptions.paths["*"] ? compilerOptions.paths["*"] : ["./node_modules/*"]).concat([
                "../../node_modules/*"
            ])) });
    }
    if (compilerOptions.paths && !compilerOptions.baseUrl) {
        compilerOptions.baseUrl = ".";
    }
    return compilerOptions;
}
exports.getCompilerOptions = getCompilerOptions;
function parseCompilerOptions(compilerOptions) {
    var parsed = typescript_1.default.parseJsonConfigFileContent({ compilerOptions: compilerOptions }, typescript_1.default.sys, ".");
    return parsed.options;
}
exports.parseCompilerOptions = parseCompilerOptions;
function getIncludes(cliArgs, options) {
    return dedupe(cliArgs.concat((options.include || []), sources_1.getAlwaysIncludeGlobs(options)));
}
exports.getIncludes = getIncludes;
