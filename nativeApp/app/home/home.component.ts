import { Component, OnInit } from "@angular/core";

@Component({
    selector: "Home",
    moduleId: module.id,
    templateUrl: "./home.component.html",
    styleUrls: ["./home.component.css"]
})
export class HomeComponent implements OnInit {
    areaSource: { Category: string, Amount: number }[] = [
        { Category: "Mar", Amount: 51 },
        { Category: "Apr", Amount: 81 },
        { Category: "May", Amount: 89 },
        { Category: "Jun", Amount: 97 }
    ];

    areaSource2: { Category: string, Amount: number }[] = [
        { Category: "Mar", Amount: 60 },
        { Category: "Apr", Amount: 87 },
        { Category: "May", Amount: 91 },
        { Category: "Jun", Amount: 95 }
    ];


    constructor() {
    }

    ngOnInit(): void {
    }
}
