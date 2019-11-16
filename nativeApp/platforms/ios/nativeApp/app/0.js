(global["webpackJsonp"] = global["webpackJsonp"] || []).push([[0],{

/***/ "./home/home-routing.module.ts":
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HomeRoutingModule", function() { return HomeRoutingModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__("@angular/core");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_angular_core__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var nativescript_angular_router__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__("nativescript-angular/router");
/* harmony import */ var nativescript_angular_router__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(nativescript_angular_router__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _home_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__("./home/home.component.ts");



var routes = [
    { path: "", component: _home_component__WEBPACK_IMPORTED_MODULE_2__["HomeComponent"] }
];
var HomeRoutingModule = /** @class */ (function () {
    function HomeRoutingModule() {
    }
    HomeRoutingModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [nativescript_angular_router__WEBPACK_IMPORTED_MODULE_1__["NativeScriptRouterModule"].forChild(routes)],
            exports: [nativescript_angular_router__WEBPACK_IMPORTED_MODULE_1__["NativeScriptRouterModule"]]
        })
    ], HomeRoutingModule);
    return HomeRoutingModule;
}());



/***/ }),

/***/ "./home/home.component.css":
/***/ (function(module, exports) {

module.exports = ".home-panel{\n    vertical-align: top; \n    font-size: 20;\n    margin: 15;\n}\n\n.description-label{\n    margin-bottom: 15;\n}\n\n.today{\n    \n}"

/***/ }),

/***/ "./home/home.component.html":
/***/ (function(module, exports) {

module.exports = "<ActionBar title=\"Social Bit- How you do this?\">\n</ActionBar>\n\n<GridLayout>\n\n    <ScrollView>\n        <StackLayout class=\"home-panel\">\n            <StackLayout>\n                <Tabs height=\"400px\">\n                    <TabStrip>\n                        <TabStripItem>\n                            <Label text=\"Today\"></Label>\n                            <!--<Image src=\"res://home\"></Image> -->\n                        </TabStripItem>\n                        <TabStripItem>\n                            <Label text=\"This Week\"></Label>\n                            <!-- <Image src=\"res://settings\"></Image> -->\n                        </TabStripItem>\n                        <TabStripItem>\n                            <Label text=\"Settings\"></Label>\n                            <!-- <Image src=\"res://search\"></Image> -->\n                        </TabStripItem>\n                    </TabStrip>\n                    <TabContentItem>\n                        <GridLayout class=\"today\">\n                            <!-- <Label text=\"Home Page\" class=\"h2 text-center\">\n                            </Label> -->\n                            <GridLayout rows=\"auto, *\" height=\"1000px\">\n                                <Label row=\"0\"\n                                    text=\"Monthly sales revenue, 2017\"\n                                    textWrap=\"true\"></Label>\n                                <RadCartesianChart row=\"1\"\n                                    style=\"font-size: 12;\">\n                                    <CategoricalAxis lineColor=\"#b0b0b0\"\n                                        lineThickness=\"1\"\n                                        tkCartesianHorizontalAxis>\n                                    </CategoricalAxis>\n                                    <LinearAxis lineColor=\"#b0b0b0\"\n                                        lineThickness=\"1\"\n                                        tkCartesianVerticalAxis></LinearAxis>\n                                    <AreaSeries tkCartesianSeries\n                                        seriesName=\"Area\"\n                                        categoryProperty=\"Category\"\n                                        [items]=\"areaSource\" stackMode=\"Stack\"\n                                        valueProperty=\"Amount\"\n                                        selectionMode=\"Series\"></AreaSeries>\n                                    <AreaSeries tkCartesianSeries\n                                        seriesName=\"Area\"\n                                        categoryProperty=\"Category\"\n                                        [items]=\"areaSource2\"\n                                        stackMode=\"Stack\"\n                                        valueProperty=\"Amount\"\n                                        selectionMode=\"Series\"></AreaSeries>\n                                    <RadCartesianChartGrid tkCartesianGrid\n                                        horizontalLinesVisible=\"true\"\n                                        verticalLinesVisible=\"false\"\n                                        verticalStripLinesVisible=\"false\"\n                                        horizontalStripLinesVisible=\"false\"\n                                        horizontalStrokeColor=\"#e5e5e5\">\n                                    </RadCartesianChartGrid>\n                                    <Palette tkCartesianPalette\n                                        seriesName=\"Area\">\n                                        <PaletteEntry tkCartesianPaletteEntry\n                                            android:fillColor=\"#b2efe6\"\n                                            ios:fillColor=\"#7fe5faf6\"\n                                            strokeColor=\"#08caab\"\n                                            strokeWidth=\"2\"></PaletteEntry>\n                                        <PaletteEntry tkCartesianPaletteEntry\n                                            android:fillColor=\"#b2d2d1\"\n                                            ios:fillColor=\"#7fe5f0f0\"\n                                            strokeColor=\"#026968\"\n                                            strokeWidth=\"2\"></PaletteEntry>\n                                    </Palette>\n                                    <Palette tkCartesianPalette\n                                        seriesName=\"Area\"\n                                        seriesState=\"Selected\">\n                                        <PaletteEntry tkCartesianPaletteEntry\n                                            android:fillColor=\"#b2efe6\"\n                                            ios:fillColor=\"#7fe5faf6\"\n                                            strokeColor=\"#026555\"\n                                            strokeWidth=\"2\"></PaletteEntry>\n                                        <PaletteEntry tkCartesianPaletteEntry\n                                            android:fillColor=\"#b2d2d1\"\n                                            ios:fillColor=\"#7fe5f0f0\"\n                                            strokeColor=\"#003434\"\n                                            strokeWidth=\"2\"></PaletteEntry>\n                                    </Palette>\n                                </RadCartesianChart>\n                            </GridLayout>\n                        </GridLayout>\n                    </TabContentItem>\n                    <TabContentItem>\n                        <GridLayout>\n                            <Label text=\"Settings Page\"\n                                class=\"h2 text-center\">\n                            </Label>\n                        </GridLayout>\n                    </TabContentItem>\n                    <TabContentItem>\n                        <GridLayout>\n                            <Label text=\"Search Page\" class=\"h2 text-center\">\n                            </Label>\n                        </GridLayout>\n                    </TabContentItem>\n                </Tabs>\n            </StackLayout>\n            <!--Add your page content here-->\n            <!--\n            <Label textWrap=\"true\" text=\"Play with NativeScript!\"\n                class=\"h2 description-label\"></Label>\n            <Label textWrap=\"true\"\n                text=\"Write code in the editor or drag and drop components to build a NativeScript mobile application.\"\n                class=\"h2 description-label\"></Label>\n            <Label textWrap=\"true\"\n                text=\"Scan the QR code with your mobile device and watch the changes sync live while you play with the code.\"\n                class=\"h2 description-label\"></Label>\n                -->\n        </StackLayout>\n    </ScrollView>\n</GridLayout>\n"

/***/ }),

/***/ "./home/home.component.ts":
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HomeComponent", function() { return HomeComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__("@angular/core");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_angular_core__WEBPACK_IMPORTED_MODULE_0__);

var HomeComponent = /** @class */ (function () {
    function HomeComponent() {
        this.areaSource = [
            { Category: "Mar", Amount: 51 },
            { Category: "Apr", Amount: 81 },
            { Category: "May", Amount: 89 },
            { Category: "Jun", Amount: 97 }
        ];
        this.areaSource2 = [
            { Category: "Mar", Amount: 60 },
            { Category: "Apr", Amount: 87 },
            { Category: "May", Amount: 91 },
            { Category: "Jun", Amount: 95 }
        ];
    }
    HomeComponent.prototype.ngOnInit = function () {
    };
    HomeComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: "Home",
            template: __importDefault(__webpack_require__("./home/home.component.html")).default,
            styles: [__importDefault(__webpack_require__("./home/home.component.css")).default]
        }),
        __metadata("design:paramtypes", [])
    ], HomeComponent);
    return HomeComponent;
}());



/***/ }),

/***/ "./home/home.module.ts":
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HomeModule", function() { return HomeModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__("@angular/core");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_angular_core__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var nativescript_angular_common__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__("nativescript-angular/common");
/* harmony import */ var nativescript_angular_common__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(nativescript_angular_common__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var nativescript_ui_sidedrawer_angular__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__("nativescript-ui-sidedrawer/angular");
/* harmony import */ var nativescript_ui_sidedrawer_angular__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_sidedrawer_angular__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var nativescript_ui_listview_angular__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__("nativescript-ui-listview/angular");
/* harmony import */ var nativescript_ui_listview_angular__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_listview_angular__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var nativescript_ui_calendar_angular__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__("nativescript-ui-calendar/angular");
/* harmony import */ var nativescript_ui_calendar_angular__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_calendar_angular__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var nativescript_ui_chart_angular__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__("nativescript-ui-chart/angular");
/* harmony import */ var nativescript_ui_chart_angular__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_chart_angular__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var nativescript_ui_dataform_angular__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__("nativescript-ui-dataform/angular");
/* harmony import */ var nativescript_ui_dataform_angular__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_dataform_angular__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var nativescript_ui_autocomplete_angular__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__("nativescript-ui-autocomplete/angular");
/* harmony import */ var nativescript_ui_autocomplete_angular__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_autocomplete_angular__WEBPACK_IMPORTED_MODULE_7__);
/* harmony import */ var nativescript_ui_gauge_angular__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__("nativescript-ui-gauge/angular");
/* harmony import */ var nativescript_ui_gauge_angular__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(nativescript_ui_gauge_angular__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var nativescript_angular_forms__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__("nativescript-angular/forms");
/* harmony import */ var nativescript_angular_forms__WEBPACK_IMPORTED_MODULE_9___default = /*#__PURE__*/__webpack_require__.n(nativescript_angular_forms__WEBPACK_IMPORTED_MODULE_9__);
/* harmony import */ var _home_routing_module__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__("./home/home-routing.module.ts");
/* harmony import */ var _home_component__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__("./home/home.component.ts");












var HomeModule = /** @class */ (function () {
    function HomeModule() {
    }
    HomeModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [
                nativescript_ui_sidedrawer_angular__WEBPACK_IMPORTED_MODULE_2__["NativeScriptUISideDrawerModule"],
                nativescript_ui_listview_angular__WEBPACK_IMPORTED_MODULE_3__["NativeScriptUIListViewModule"],
                nativescript_ui_calendar_angular__WEBPACK_IMPORTED_MODULE_4__["NativeScriptUICalendarModule"],
                nativescript_ui_chart_angular__WEBPACK_IMPORTED_MODULE_5__["NativeScriptUIChartModule"],
                nativescript_ui_dataform_angular__WEBPACK_IMPORTED_MODULE_6__["NativeScriptUIDataFormModule"],
                nativescript_ui_autocomplete_angular__WEBPACK_IMPORTED_MODULE_7__["NativeScriptUIAutoCompleteTextViewModule"],
                nativescript_ui_gauge_angular__WEBPACK_IMPORTED_MODULE_8__["NativeScriptUIGaugeModule"],
                nativescript_angular_common__WEBPACK_IMPORTED_MODULE_1__["NativeScriptCommonModule"],
                _home_routing_module__WEBPACK_IMPORTED_MODULE_10__["HomeRoutingModule"],
                nativescript_angular_forms__WEBPACK_IMPORTED_MODULE_9__["NativeScriptFormsModule"]
            ],
            declarations: [
                _home_component__WEBPACK_IMPORTED_MODULE_11__["HomeComponent"]
            ],
            schemas: [
                _angular_core__WEBPACK_IMPORTED_MODULE_0__["NO_ERRORS_SCHEMA"]
            ]
        })
    ], HomeModule);
    return HomeModule;
}());



/***/ })

}]);
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIndlYnBhY2s6Ly8vLi9ob21lL2hvbWUtcm91dGluZy5tb2R1bGUudHMiLCJ3ZWJwYWNrOi8vLy4vaG9tZS9ob21lLmNvbXBvbmVudC5jc3MiLCJ3ZWJwYWNrOi8vLy4vaG9tZS9ob21lLmNvbXBvbmVudC5odG1sIiwid2VicGFjazovLy8uL2hvbWUvaG9tZS5jb21wb25lbnQudHMiLCJ3ZWJwYWNrOi8vLy4vaG9tZS9ob21lLm1vZHVsZS50cyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiOzs7Ozs7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUF5QztBQUU4QjtBQUV0QjtBQUVqRCxJQUFNLE1BQU0sR0FBVztJQUNuQixFQUFFLElBQUksRUFBRSxFQUFFLEVBQUUsU0FBUyxFQUFFLDZEQUFhLEVBQUU7Q0FDekMsQ0FBQztBQU1GO0lBQUE7SUFBaUMsQ0FBQztJQUFyQixpQkFBaUI7UUFKN0IsOERBQVEsQ0FBQztZQUNOLE9BQU8sRUFBRSxDQUFDLG9GQUF3QixDQUFDLFFBQVEsQ0FBQyxNQUFNLENBQUMsQ0FBQztZQUNwRCxPQUFPLEVBQUUsQ0FBQyxvRkFBd0IsQ0FBQztTQUN0QyxDQUFDO09BQ1csaUJBQWlCLENBQUk7SUFBRCx3QkFBQztDQUFBO0FBQUo7Ozs7Ozs7O0FDZDlCLDhCQUE4QiwwQkFBMEIscUJBQXFCLGlCQUFpQixHQUFHLHVCQUF1Qix3QkFBd0IsR0FBRyxXQUFXLFNBQVMsQzs7Ozs7OztBQ0F2SyxvaERBQW9oRCx3dEs7Ozs7Ozs7O0FDQXBoRDtBQUFBO0FBQUE7QUFBQTtBQUFrRDtBQVFsRDtJQWdCSTtRQWZBLGVBQVUsR0FBMkM7WUFDakQsRUFBRSxRQUFRLEVBQUUsS0FBSyxFQUFFLE1BQU0sRUFBRSxFQUFFLEVBQUU7WUFDL0IsRUFBRSxRQUFRLEVBQUUsS0FBSyxFQUFFLE1BQU0sRUFBRSxFQUFFLEVBQUU7WUFDL0IsRUFBRSxRQUFRLEVBQUUsS0FBSyxFQUFFLE1BQU0sRUFBRSxFQUFFLEVBQUU7WUFDL0IsRUFBRSxRQUFRLEVBQUUsS0FBSyxFQUFFLE1BQU0sRUFBRSxFQUFFLEVBQUU7U0FDbEMsQ0FBQztRQUVGLGdCQUFXLEdBQTJDO1lBQ2xELEVBQUUsUUFBUSxFQUFFLEtBQUssRUFBRSxNQUFNLEVBQUUsRUFBRSxFQUFFO1lBQy9CLEVBQUUsUUFBUSxFQUFFLEtBQUssRUFBRSxNQUFNLEVBQUUsRUFBRSxFQUFFO1lBQy9CLEVBQUUsUUFBUSxFQUFFLEtBQUssRUFBRSxNQUFNLEVBQUUsRUFBRSxFQUFFO1lBQy9CLEVBQUUsUUFBUSxFQUFFLEtBQUssRUFBRSxNQUFNLEVBQUUsRUFBRSxFQUFFO1NBQ2xDLENBQUM7SUFJRixDQUFDO0lBRUQsZ0NBQVEsR0FBUjtJQUNBLENBQUM7SUFwQlEsYUFBYTtRQU56QiwrREFBUyxDQUFDO1lBQ1AsUUFBUSxFQUFFLE1BQU07WUFFaEIsb0ZBQW9DOztTQUV2QyxDQUFDOztPQUNXLGFBQWEsQ0FxQnpCO0lBQUQsb0JBQUM7Q0FBQTtBQXJCeUI7Ozs7Ozs7OztBQ1IxQjtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQUE7QUFBMkQ7QUFDWTtBQUNhO0FBQ0o7QUFDQTtBQUNOO0FBQ007QUFDZ0I7QUFDdEI7QUFDTDtBQUVYO0FBQ1Q7QUFzQmpEO0lBQUE7SUFBMEIsQ0FBQztJQUFkLFVBQVU7UUFwQnRCLDhEQUFRLENBQUM7WUFDTixPQUFPLEVBQUU7Z0JBQ0wsaUdBQThCO2dCQUM5Qiw2RkFBNEI7Z0JBQzVCLDZGQUE0QjtnQkFDNUIsdUZBQXlCO2dCQUN6Qiw2RkFBNEI7Z0JBQzVCLDZHQUF3QztnQkFDeEMsdUZBQXlCO2dCQUN6QixvRkFBd0I7Z0JBQ3hCLHVFQUFpQjtnQkFDakIsa0ZBQXVCO2FBQzFCO1lBQ0QsWUFBWSxFQUFFO2dCQUNWLDhEQUFhO2FBQ2hCO1lBQ0QsT0FBTyxFQUFFO2dCQUNMLDhEQUFnQjthQUNuQjtTQUNKLENBQUM7T0FDVyxVQUFVLENBQUk7SUFBRCxpQkFBQztDQUFBO0FBQUoiLCJmaWxlIjoiMC5qcyIsInNvdXJjZXNDb250ZW50IjpbImltcG9ydCB7IE5nTW9kdWxlIH0gZnJvbSBcIkBhbmd1bGFyL2NvcmVcIjtcbmltcG9ydCB7IFJvdXRlcyB9IGZyb20gXCJAYW5ndWxhci9yb3V0ZXJcIjtcbmltcG9ydCB7IE5hdGl2ZVNjcmlwdFJvdXRlck1vZHVsZSB9IGZyb20gXCJuYXRpdmVzY3JpcHQtYW5ndWxhci9yb3V0ZXJcIjtcblxuaW1wb3J0IHsgSG9tZUNvbXBvbmVudCB9IGZyb20gXCIuL2hvbWUuY29tcG9uZW50XCI7XG5cbmNvbnN0IHJvdXRlczogUm91dGVzID0gW1xuICAgIHsgcGF0aDogXCJcIiwgY29tcG9uZW50OiBIb21lQ29tcG9uZW50IH1cbl07XG5cbkBOZ01vZHVsZSh7XG4gICAgaW1wb3J0czogW05hdGl2ZVNjcmlwdFJvdXRlck1vZHVsZS5mb3JDaGlsZChyb3V0ZXMpXSxcbiAgICBleHBvcnRzOiBbTmF0aXZlU2NyaXB0Um91dGVyTW9kdWxlXVxufSlcbmV4cG9ydCBjbGFzcyBIb21lUm91dGluZ01vZHVsZSB7IH1cbiIsIm1vZHVsZS5leHBvcnRzID0gXCIuaG9tZS1wYW5lbHtcXG4gICAgdmVydGljYWwtYWxpZ246IHRvcDsgXFxuICAgIGZvbnQtc2l6ZTogMjA7XFxuICAgIG1hcmdpbjogMTU7XFxufVxcblxcbi5kZXNjcmlwdGlvbi1sYWJlbHtcXG4gICAgbWFyZ2luLWJvdHRvbTogMTU7XFxufVxcblxcbi50b2RheXtcXG4gICAgXFxufVwiIiwibW9kdWxlLmV4cG9ydHMgPSBcIjxBY3Rpb25CYXIgdGl0bGU9XFxcIlNvY2lhbCBCaXQtIEhvdyB5b3UgZG8gdGhpcz9cXFwiPlxcbjwvQWN0aW9uQmFyPlxcblxcbjxHcmlkTGF5b3V0PlxcblxcbiAgICA8U2Nyb2xsVmlldz5cXG4gICAgICAgIDxTdGFja0xheW91dCBjbGFzcz1cXFwiaG9tZS1wYW5lbFxcXCI+XFxuICAgICAgICAgICAgPFN0YWNrTGF5b3V0PlxcbiAgICAgICAgICAgICAgICA8VGFicyBoZWlnaHQ9XFxcIjQwMHB4XFxcIj5cXG4gICAgICAgICAgICAgICAgICAgIDxUYWJTdHJpcD5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8VGFiU3RyaXBJdGVtPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8TGFiZWwgdGV4dD1cXFwiVG9kYXlcXFwiPjwvTGFiZWw+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgIDwhLS08SW1hZ2Ugc3JjPVxcXCJyZXM6Ly9ob21lXFxcIj48L0ltYWdlPiAtLT5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8L1RhYlN0cmlwSXRlbT5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8VGFiU3RyaXBJdGVtPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8TGFiZWwgdGV4dD1cXFwiVGhpcyBXZWVrXFxcIj48L0xhYmVsPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8IS0tIDxJbWFnZSBzcmM9XFxcInJlczovL3NldHRpbmdzXFxcIj48L0ltYWdlPiAtLT5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8L1RhYlN0cmlwSXRlbT5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8VGFiU3RyaXBJdGVtPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8TGFiZWwgdGV4dD1cXFwiU2V0dGluZ3NcXFwiPjwvTGFiZWw+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgIDwhLS0gPEltYWdlIHNyYz1cXFwicmVzOi8vc2VhcmNoXFxcIj48L0ltYWdlPiAtLT5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8L1RhYlN0cmlwSXRlbT5cXG4gICAgICAgICAgICAgICAgICAgIDwvVGFiU3RyaXA+XFxuICAgICAgICAgICAgICAgICAgICA8VGFiQ29udGVudEl0ZW0+XFxuICAgICAgICAgICAgICAgICAgICAgICAgPEdyaWRMYXlvdXQgY2xhc3M9XFxcInRvZGF5XFxcIj5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgPCEtLSA8TGFiZWwgdGV4dD1cXFwiSG9tZSBQYWdlXFxcIiBjbGFzcz1cXFwiaDIgdGV4dC1jZW50ZXJcXFwiPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8L0xhYmVsPiAtLT5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgPEdyaWRMYXlvdXQgcm93cz1cXFwiYXV0bywgKlxcXCIgaGVpZ2h0PVxcXCIxMDAwcHhcXFwiPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPExhYmVsIHJvdz1cXFwiMFxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICB0ZXh0PVxcXCJNb250aGx5IHNhbGVzIHJldmVudWUsIDIwMTdcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgdGV4dFdyYXA9XFxcInRydWVcXFwiPjwvTGFiZWw+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICA8UmFkQ2FydGVzaWFuQ2hhcnQgcm93PVxcXCIxXFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHN0eWxlPVxcXCJmb250LXNpemU6IDEyO1xcXCI+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPENhdGVnb3JpY2FsQXhpcyBsaW5lQ29sb3I9XFxcIiNiMGIwYjBcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGxpbmVUaGlja25lc3M9XFxcIjFcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHRrQ2FydGVzaWFuSG9yaXpvbnRhbEF4aXM+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPC9DYXRlZ29yaWNhbEF4aXM+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPExpbmVhckF4aXMgbGluZUNvbG9yPVxcXCIjYjBiMGIwXFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBsaW5lVGhpY2tuZXNzPVxcXCIxXFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICB0a0NhcnRlc2lhblZlcnRpY2FsQXhpcz48L0xpbmVhckF4aXM+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPEFyZWFTZXJpZXMgdGtDYXJ0ZXNpYW5TZXJpZXNcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc2VyaWVzTmFtZT1cXFwiQXJlYVxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY2F0ZWdvcnlQcm9wZXJ0eT1cXFwiQ2F0ZWdvcnlcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIFtpdGVtc109XFxcImFyZWFTb3VyY2VcXFwiIHN0YWNrTW9kZT1cXFwiU3RhY2tcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHZhbHVlUHJvcGVydHk9XFxcIkFtb3VudFxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc2VsZWN0aW9uTW9kZT1cXFwiU2VyaWVzXFxcIj48L0FyZWFTZXJpZXM+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPEFyZWFTZXJpZXMgdGtDYXJ0ZXNpYW5TZXJpZXNcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc2VyaWVzTmFtZT1cXFwiQXJlYVxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY2F0ZWdvcnlQcm9wZXJ0eT1cXFwiQ2F0ZWdvcnlcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIFtpdGVtc109XFxcImFyZWFTb3VyY2UyXFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBzdGFja01vZGU9XFxcIlN0YWNrXFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICB2YWx1ZVByb3BlcnR5PVxcXCJBbW91bnRcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHNlbGVjdGlvbk1vZGU9XFxcIlNlcmllc1xcXCI+PC9BcmVhU2VyaWVzPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIDxSYWRDYXJ0ZXNpYW5DaGFydEdyaWQgdGtDYXJ0ZXNpYW5HcmlkXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGhvcml6b250YWxMaW5lc1Zpc2libGU9XFxcInRydWVcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHZlcnRpY2FsTGluZXNWaXNpYmxlPVxcXCJmYWxzZVxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgdmVydGljYWxTdHJpcExpbmVzVmlzaWJsZT1cXFwiZmFsc2VcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGhvcml6b250YWxTdHJpcExpbmVzVmlzaWJsZT1cXFwiZmFsc2VcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGhvcml6b250YWxTdHJva2VDb2xvcj1cXFwiI2U1ZTVlNVxcXCI+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPC9SYWRDYXJ0ZXNpYW5DaGFydEdyaWQ+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPFBhbGV0dGUgdGtDYXJ0ZXNpYW5QYWxldHRlXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHNlcmllc05hbWU9XFxcIkFyZWFcXFwiPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICA8UGFsZXR0ZUVudHJ5IHRrQ2FydGVzaWFuUGFsZXR0ZUVudHJ5XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBhbmRyb2lkOmZpbGxDb2xvcj1cXFwiI2IyZWZlNlxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGlvczpmaWxsQ29sb3I9XFxcIiM3ZmU1ZmFmNlxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHN0cm9rZUNvbG9yPVxcXCIjMDhjYWFiXFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc3Ryb2tlV2lkdGg9XFxcIjJcXFwiPjwvUGFsZXR0ZUVudHJ5PlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICA8UGFsZXR0ZUVudHJ5IHRrQ2FydGVzaWFuUGFsZXR0ZUVudHJ5XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBhbmRyb2lkOmZpbGxDb2xvcj1cXFwiI2IyZDJkMVxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGlvczpmaWxsQ29sb3I9XFxcIiM3ZmU1ZjBmMFxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHN0cm9rZUNvbG9yPVxcXCIjMDI2OTY4XFxcIlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc3Ryb2tlV2lkdGg9XFxcIjJcXFwiPjwvUGFsZXR0ZUVudHJ5PlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIDwvUGFsZXR0ZT5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICA8UGFsZXR0ZSB0a0NhcnRlc2lhblBhbGV0dGVcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc2VyaWVzTmFtZT1cXFwiQXJlYVxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgc2VyaWVzU3RhdGU9XFxcIlNlbGVjdGVkXFxcIj5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPFBhbGV0dGVFbnRyeSB0a0NhcnRlc2lhblBhbGV0dGVFbnRyeVxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgYW5kcm9pZDpmaWxsQ29sb3I9XFxcIiNiMmVmZTZcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBpb3M6ZmlsbENvbG9yPVxcXCIjN2ZlNWZhZjZcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBzdHJva2VDb2xvcj1cXFwiIzAyNjU1NVxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHN0cm9rZVdpZHRoPVxcXCIyXFxcIj48L1BhbGV0dGVFbnRyeT5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgPFBhbGV0dGVFbnRyeSB0a0NhcnRlc2lhblBhbGV0dGVFbnRyeVxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgYW5kcm9pZDpmaWxsQ29sb3I9XFxcIiNiMmQyZDFcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBpb3M6ZmlsbENvbG9yPVxcXCIjN2ZlNWYwZjBcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBzdHJva2VDb2xvcj1cXFwiIzAwMzQzNFxcXCJcXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHN0cm9rZVdpZHRoPVxcXCIyXFxcIj48L1BhbGV0dGVFbnRyeT5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICA8L1BhbGV0dGU+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICA8L1JhZENhcnRlc2lhbkNoYXJ0PlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8L0dyaWRMYXlvdXQ+XFxuICAgICAgICAgICAgICAgICAgICAgICAgPC9HcmlkTGF5b3V0PlxcbiAgICAgICAgICAgICAgICAgICAgPC9UYWJDb250ZW50SXRlbT5cXG4gICAgICAgICAgICAgICAgICAgIDxUYWJDb250ZW50SXRlbT5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8R3JpZExheW91dD5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgPExhYmVsIHRleHQ9XFxcIlNldHRpbmdzIFBhZ2VcXFwiXFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBjbGFzcz1cXFwiaDIgdGV4dC1jZW50ZXJcXFwiPlxcbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8L0xhYmVsPlxcbiAgICAgICAgICAgICAgICAgICAgICAgIDwvR3JpZExheW91dD5cXG4gICAgICAgICAgICAgICAgICAgIDwvVGFiQ29udGVudEl0ZW0+XFxuICAgICAgICAgICAgICAgICAgICA8VGFiQ29udGVudEl0ZW0+XFxuICAgICAgICAgICAgICAgICAgICAgICAgPEdyaWRMYXlvdXQ+XFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgIDxMYWJlbCB0ZXh0PVxcXCJTZWFyY2ggUGFnZVxcXCIgY2xhc3M9XFxcImgyIHRleHQtY2VudGVyXFxcIj5cXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgPC9MYWJlbD5cXG4gICAgICAgICAgICAgICAgICAgICAgICA8L0dyaWRMYXlvdXQ+XFxuICAgICAgICAgICAgICAgICAgICA8L1RhYkNvbnRlbnRJdGVtPlxcbiAgICAgICAgICAgICAgICA8L1RhYnM+XFxuICAgICAgICAgICAgPC9TdGFja0xheW91dD5cXG4gICAgICAgICAgICA8IS0tQWRkIHlvdXIgcGFnZSBjb250ZW50IGhlcmUtLT5cXG4gICAgICAgICAgICA8IS0tXFxuICAgICAgICAgICAgPExhYmVsIHRleHRXcmFwPVxcXCJ0cnVlXFxcIiB0ZXh0PVxcXCJQbGF5IHdpdGggTmF0aXZlU2NyaXB0IVxcXCJcXG4gICAgICAgICAgICAgICAgY2xhc3M9XFxcImgyIGRlc2NyaXB0aW9uLWxhYmVsXFxcIj48L0xhYmVsPlxcbiAgICAgICAgICAgIDxMYWJlbCB0ZXh0V3JhcD1cXFwidHJ1ZVxcXCJcXG4gICAgICAgICAgICAgICAgdGV4dD1cXFwiV3JpdGUgY29kZSBpbiB0aGUgZWRpdG9yIG9yIGRyYWcgYW5kIGRyb3AgY29tcG9uZW50cyB0byBidWlsZCBhIE5hdGl2ZVNjcmlwdCBtb2JpbGUgYXBwbGljYXRpb24uXFxcIlxcbiAgICAgICAgICAgICAgICBjbGFzcz1cXFwiaDIgZGVzY3JpcHRpb24tbGFiZWxcXFwiPjwvTGFiZWw+XFxuICAgICAgICAgICAgPExhYmVsIHRleHRXcmFwPVxcXCJ0cnVlXFxcIlxcbiAgICAgICAgICAgICAgICB0ZXh0PVxcXCJTY2FuIHRoZSBRUiBjb2RlIHdpdGggeW91ciBtb2JpbGUgZGV2aWNlIGFuZCB3YXRjaCB0aGUgY2hhbmdlcyBzeW5jIGxpdmUgd2hpbGUgeW91IHBsYXkgd2l0aCB0aGUgY29kZS5cXFwiXFxuICAgICAgICAgICAgICAgIGNsYXNzPVxcXCJoMiBkZXNjcmlwdGlvbi1sYWJlbFxcXCI+PC9MYWJlbD5cXG4gICAgICAgICAgICAgICAgLS0+XFxuICAgICAgICA8L1N0YWNrTGF5b3V0PlxcbiAgICA8L1Njcm9sbFZpZXc+XFxuPC9HcmlkTGF5b3V0PlxcblwiIiwiaW1wb3J0IHsgQ29tcG9uZW50LCBPbkluaXQgfSBmcm9tIFwiQGFuZ3VsYXIvY29yZVwiO1xuXG5AQ29tcG9uZW50KHtcbiAgICBzZWxlY3RvcjogXCJIb21lXCIsXG4gICAgbW9kdWxlSWQ6IG1vZHVsZS5pZCxcbiAgICB0ZW1wbGF0ZVVybDogXCIuL2hvbWUuY29tcG9uZW50Lmh0bWxcIixcbiAgICBzdHlsZVVybHM6IFtcIi4vaG9tZS5jb21wb25lbnQuY3NzXCJdXG59KVxuZXhwb3J0IGNsYXNzIEhvbWVDb21wb25lbnQgaW1wbGVtZW50cyBPbkluaXQge1xuICAgIGFyZWFTb3VyY2U6IHsgQ2F0ZWdvcnk6IHN0cmluZywgQW1vdW50OiBudW1iZXIgfVtdID0gW1xuICAgICAgICB7IENhdGVnb3J5OiBcIk1hclwiLCBBbW91bnQ6IDUxIH0sXG4gICAgICAgIHsgQ2F0ZWdvcnk6IFwiQXByXCIsIEFtb3VudDogODEgfSxcbiAgICAgICAgeyBDYXRlZ29yeTogXCJNYXlcIiwgQW1vdW50OiA4OSB9LFxuICAgICAgICB7IENhdGVnb3J5OiBcIkp1blwiLCBBbW91bnQ6IDk3IH1cbiAgICBdO1xuXG4gICAgYXJlYVNvdXJjZTI6IHsgQ2F0ZWdvcnk6IHN0cmluZywgQW1vdW50OiBudW1iZXIgfVtdID0gW1xuICAgICAgICB7IENhdGVnb3J5OiBcIk1hclwiLCBBbW91bnQ6IDYwIH0sXG4gICAgICAgIHsgQ2F0ZWdvcnk6IFwiQXByXCIsIEFtb3VudDogODcgfSxcbiAgICAgICAgeyBDYXRlZ29yeTogXCJNYXlcIiwgQW1vdW50OiA5MSB9LFxuICAgICAgICB7IENhdGVnb3J5OiBcIkp1blwiLCBBbW91bnQ6IDk1IH1cbiAgICBdO1xuXG5cbiAgICBjb25zdHJ1Y3RvcigpIHtcbiAgICB9XG5cbiAgICBuZ09uSW5pdCgpOiB2b2lkIHtcbiAgICB9XG59XG4iLCJpbXBvcnQgeyBOZ01vZHVsZSwgTk9fRVJST1JTX1NDSEVNQSB9IGZyb20gXCJAYW5ndWxhci9jb3JlXCI7XG5pbXBvcnQgeyBOYXRpdmVTY3JpcHRDb21tb25Nb2R1bGUgfSBmcm9tIFwibmF0aXZlc2NyaXB0LWFuZ3VsYXIvY29tbW9uXCI7XG5pbXBvcnQgeyBOYXRpdmVTY3JpcHRVSVNpZGVEcmF3ZXJNb2R1bGUgfSBmcm9tIFwibmF0aXZlc2NyaXB0LXVpLXNpZGVkcmF3ZXIvYW5ndWxhclwiO1xuaW1wb3J0IHsgTmF0aXZlU2NyaXB0VUlMaXN0Vmlld01vZHVsZSB9IGZyb20gXCJuYXRpdmVzY3JpcHQtdWktbGlzdHZpZXcvYW5ndWxhclwiO1xuaW1wb3J0IHsgTmF0aXZlU2NyaXB0VUlDYWxlbmRhck1vZHVsZSB9IGZyb20gXCJuYXRpdmVzY3JpcHQtdWktY2FsZW5kYXIvYW5ndWxhclwiO1xuaW1wb3J0IHsgTmF0aXZlU2NyaXB0VUlDaGFydE1vZHVsZSB9IGZyb20gXCJuYXRpdmVzY3JpcHQtdWktY2hhcnQvYW5ndWxhclwiO1xuaW1wb3J0IHsgTmF0aXZlU2NyaXB0VUlEYXRhRm9ybU1vZHVsZSB9IGZyb20gXCJuYXRpdmVzY3JpcHQtdWktZGF0YWZvcm0vYW5ndWxhclwiO1xuaW1wb3J0IHsgTmF0aXZlU2NyaXB0VUlBdXRvQ29tcGxldGVUZXh0Vmlld01vZHVsZSB9IGZyb20gXCJuYXRpdmVzY3JpcHQtdWktYXV0b2NvbXBsZXRlL2FuZ3VsYXJcIjtcbmltcG9ydCB7IE5hdGl2ZVNjcmlwdFVJR2F1Z2VNb2R1bGUgfSBmcm9tIFwibmF0aXZlc2NyaXB0LXVpLWdhdWdlL2FuZ3VsYXJcIjtcbmltcG9ydCB7IE5hdGl2ZVNjcmlwdEZvcm1zTW9kdWxlIH0gZnJvbSBcIm5hdGl2ZXNjcmlwdC1hbmd1bGFyL2Zvcm1zXCI7XG5cbmltcG9ydCB7IEhvbWVSb3V0aW5nTW9kdWxlIH0gZnJvbSBcIi4vaG9tZS1yb3V0aW5nLm1vZHVsZVwiO1xuaW1wb3J0IHsgSG9tZUNvbXBvbmVudCB9IGZyb20gXCIuL2hvbWUuY29tcG9uZW50XCI7XG5cbkBOZ01vZHVsZSh7XG4gICAgaW1wb3J0czogW1xuICAgICAgICBOYXRpdmVTY3JpcHRVSVNpZGVEcmF3ZXJNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdFVJTGlzdFZpZXdNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdFVJQ2FsZW5kYXJNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdFVJQ2hhcnRNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdFVJRGF0YUZvcm1Nb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdFVJQXV0b0NvbXBsZXRlVGV4dFZpZXdNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdFVJR2F1Z2VNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdENvbW1vbk1vZHVsZSxcbiAgICAgICAgSG9tZVJvdXRpbmdNb2R1bGUsXG4gICAgICAgIE5hdGl2ZVNjcmlwdEZvcm1zTW9kdWxlXG4gICAgXSxcbiAgICBkZWNsYXJhdGlvbnM6IFtcbiAgICAgICAgSG9tZUNvbXBvbmVudFxuICAgIF0sXG4gICAgc2NoZW1hczogW1xuICAgICAgICBOT19FUlJPUlNfU0NIRU1BXG4gICAgXVxufSlcbmV4cG9ydCBjbGFzcyBIb21lTW9kdWxlIHsgfVxuIl0sInNvdXJjZVJvb3QiOiIifQ==