"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var path = __importStar(require("path"));
var typescript_1 = __importDefault(require("typescript"));
var compiler_1 = require("../compiler");
var json_files_1 = require("../json-files");
var json_update_1 = require("../json-update");
var options_1 = require("../options");
var sources_1 = require("../sources");
var tsconfig_1 = require("../tsconfig");
exports.help = "\nUsage\n  $ ts\n  $ ts [build] --out-dir <path> <...entrypoint files>\n  $ ts [build] [--declaration] [--emit-tsconfig] [--lint] [--out-dir <path>] [<...entrypoint files>]\n\nArguments\n  Pass any glob pattern(s) of the files to compile, like 'src/**/*.ts' or '!src/**/*.test.(ts|tsx)'.\n  You only need to pass the entrypoints of your program.\n\nOptions\n  --declaration         Create declaration files (*.d.ts) in output directory. Defaults to true.\n  --emit-tsconfig       Create/update tsconfig.json file.\n  --emit-tslint         Create/update tslint.json file.\n  --help                Print this help.\n  --jsx <option>        Enable JSX support in TSX files. Set to \"react\", \"react-native\" or \"preserve\".\n  --lib <...lib>        Set features available at runtime: ES5, ES2015, ..., DOM, WebWorker, ...\n  --monorepo            Indicates a monorepo package. Will look for types in package and monorepo root.\n  --no-strict           Disable strict mode.\n  --out-dir, -o <path>  Set the output directory. Defaults to dist/.\n  --out-module <type>   Set the output module type: \"commonjs\" (default), \"es2015\", \"umd\", ...\n  --root-dir <path>     Set the source directory. Used to\n  --skip-lib-check      Don't type-check declaration files (*.d.ts).\n  --source-maps         Create source maps.\n  --target, -t <target> Set target: ES5, ES2015, ..., ESNext\n  --transform <module>  Enable custom TypeScript transformation. Pass a package name or relative module path.\n  --typings-dir <path>  Set the custom 3rd-party module declaration directory. Defaults to \"typings/\".\n\nTS options and compiler options can be set in the package.json file, too.\n\nSee <https://github.com/andywer/ts> for CLI details.\nSee <https://www.typescriptlang.org/docs/handbook/compiler-options.html> for compiler options details.\n";
var dedupe = function (array) { return Array.from(new Set(array)); };
var formatHost = {
    getCanonicalFileName: function (filePath) { return filePath; },
    getCurrentDirectory: typescript_1.default.sys.getCurrentDirectory,
    getNewLine: function () { return typescript_1.default.sys.newLine; }
};
function fail(message) {
    console.error(message);
    return process.exit(1);
}
function filePathIsIn(filePath, dirPath) {
    return path.resolve(filePath).startsWith(path.resolve(dirPath));
}
function run(cli) {
    return __awaiter(this, void 0, void 0, function () {
        var packageJsonData, tsconfigJsonPath, tsconfigJsonData, _a, options, compilerOptionsJson, compilerOptions, tsConfigCreated, sourceGlobs, allInputGlobs, allInputFilePaths, sourceFilePaths, startingTime, _b, diagnostics, result;
        return __generator(this, function (_c) {
            switch (_c.label) {
                case 0: return [4 /*yield*/, json_files_1.readJsonFile(json_files_1.locatePackageJson() || fail("Could not locate package.json file."))];
                case 1:
                    packageJsonData = _c.sent();
                    tsconfigJsonPath = json_files_1.locateTSConfigJson();
                    if (!tsconfigJsonPath) return [3 /*break*/, 3];
                    return [4 /*yield*/, json_files_1.readJsonFile(tsconfigJsonPath)];
                case 2:
                    _a = _c.sent();
                    return [3 /*break*/, 4];
                case 3:
                    _a = {};
                    _c.label = 4;
                case 4:
                    tsconfigJsonData = _a;
                    options = options_1.getOptions(cli.flags, packageJsonData, tsconfigJsonData);
                    compilerOptionsJson = tsconfig_1.getCompilerOptions(cli.flags, options, packageJsonData, tsconfigJsonData);
                    compilerOptions = tsconfig_1.parseCompilerOptions(compilerOptionsJson);
                    if (!options.emitTSConfig) return [3 /*break*/, 6];
                    return [4 /*yield*/, json_update_1.createOrUpdateJSON("tsconfig.json", {
                            compilerOptions: compilerOptionsJson,
                            include: tsconfig_1.getIncludes(cli.input, options)
                        })];
                case 5:
                    tsConfigCreated = _c.sent();
                    if (tsConfigCreated) {
                        console.log("Created tsconfig.json file.");
                    }
                    _c.label = 6;
                case 6:
                    sourceGlobs = dedupe(sources_1.getSourceGlobs(cli.input, options).concat((options.include || [])));
                    allInputGlobs = dedupe(sources_1.getAlwaysIncludeGlobs(options).concat(sourceGlobs));
                    return [4 /*yield*/, sources_1.resolveGlobs(allInputGlobs)];
                case 7:
                    allInputFilePaths = _c.sent();
                    return [4 /*yield*/, sources_1.resolveGlobs(sourceGlobs)];
                case 8:
                    sourceFilePaths = _c.sent();
                    if (sourceFilePaths.length === 0) {
                        fail("No matching source files found: " + sourceGlobs.join(", "));
                    }
                    if (compilerOptions.rootDir && sourceFilePaths.some(function (filePath) { return !filePathIsIn(filePath, compilerOptions.rootDir); })) {
                        console.error("Warning: Some source files are not located within the specified source root directory (" + compilerOptions.rootDir + "). Disabling the source root directory compiler option.");
                        compilerOptions.rootDir = undefined;
                    }
                    startingTime = Date.now();
                    _b = compiler_1.compileOnce(allInputFilePaths, compilerOptions, options), diagnostics = _b.diagnostics, result = _b.result;
                    // TODO: Support watch mode
                    if (result.emitSkipped) {
                        console.error("Build failed:");
                        console.error(typescript_1.default.formatDiagnosticsWithColorAndContext(diagnostics, formatHost));
                        process.exit(1);
                    }
                    else {
                        console.log(typescript_1.default.formatDiagnosticsWithColorAndContext(diagnostics, formatHost));
                        console.log("Compiled in " + ((Date.now() - startingTime) / 1000).toFixed(1) + "s");
                    }
                    return [2 /*return*/];
            }
        });
    });
}
exports.run = run;
