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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
var axios_1 = __importDefault(require("axios"));
var figures = __importStar(require("figures"));
exports.help = "\nUsage\n  $ ts search <package-name>\n\nArguments\n  Pass any package name to look for type declarations published to npm.\n  Will scan for \"@types/<package-name>\" and \"@*/types-<package-name>\" packages.\n\nOptions\n  --help                Print this help.\n";
function fetchTypePackageNames(partialPackageName) {
    return __awaiter(this, void 0, void 0, function () {
        var response, results;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0: return [4 /*yield*/, axios_1.default.get("http://npmsearch.com/query?q=name:(" + encodeURIComponent("types AND " + partialPackageName + "*") + ")&fields=name,rating&sort=rating:desc")];
                case 1:
                    response = _a.sent();
                    results = response.data.results;
                    return [2 /*return*/, results];
            }
        });
    });
}
function filterResults(results) {
    return results.filter(function (result) { return result.name[0].startsWith("@types/") || result.name[0].match(/^@[^\/]+\/types-/); });
}
function getTypePackageBaseName(packageName) {
    return packageName.replace(/^@types\//, "").replace(/^@[^\/]+\/types-/, "");
}
function sortResults(results, packageName) {
    var customTypesPackageNames = results.filter(function (result) { return !result.name[0].startsWith("@types/"); });
    var defTypedPackageNames = results.filter(function (result) { return result.name[0].startsWith("@types/"); });
    var sorter = function (result1, result2) {
        var baseName1 = getTypePackageBaseName(result1.name[0]);
        var baseName2 = getTypePackageBaseName(result2.name[0]);
        if (baseName2.startsWith(packageName) && !baseName1.startsWith(packageName)) {
            return 1;
        }
        else if (baseName2.length < baseName1.length) {
            return 1;
        }
        else {
            return -1;
        }
    };
    return defTypedPackageNames.sort(sorter).concat(customTypesPackageNames.sort(sorter));
}
function run(cli) {
    return __awaiter(this, void 0, void 0, function () {
        var packageName, results, preparedResults, _i, preparedResults_1, result;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    if (cli.input.length !== 1) {
                        console.error(exports.help);
                        process.exit(1);
                    }
                    packageName = cli.input[0];
                    return [4 /*yield*/, fetchTypePackageNames(packageName)];
                case 1:
                    results = _a.sent();
                    if (results.length === 0) {
                        console.log(figures.cross + " No matches");
                    }
                    else {
                        preparedResults = sortResults(filterResults(results), packageName);
                        console.log("Type declaration packages:\n");
                        for (_i = 0, preparedResults_1 = preparedResults; _i < preparedResults_1.length; _i++) {
                            result = preparedResults_1[_i];
                            console.log("  " + result.name[0]);
                        }
                    }
                    return [2 /*return*/];
            }
        });
    });
}
exports.run = run;
